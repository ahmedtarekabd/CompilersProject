import streamlit as st
import subprocess
import os
from streamlit_monaco import st_monaco  # Monaco editor integration

# Define working directory as the current directory of the script
FLEX_BISON_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
WORK_DIR = os.path.dirname(os.path.abspath(__file__))
TEMP_DIR = os.path.join(WORK_DIR, "temp_files")

# Ensure the temporary directory exists
os.makedirs(TEMP_DIR, exist_ok=True)

# Function to save the uploaded file to a temporary location
def save_uploaded_file(uploaded_file):
    temp_file_path = os.path.join(TEMP_DIR, uploaded_file.name)
    with open(temp_file_path, "wb") as f:
        f.write(uploaded_file.getbuffer())
    return temp_file_path

def save_edited_file(file_path, content):
    with open(file_path, "w") as f:
        f.write(content)
    st.success(f"File saved successfully: {file_path}")

def run_make():
    try:
        # Run flex and bison commands
        subprocess.run(["flex", "Lexer.l"], check=True, cwd=FLEX_BISON_DIR)
        subprocess.run(["bison", "-d", "Parser.y"], check=True, cwd=FLEX_BISON_DIR)
        # Compile generated C files into compiler.exe
        subprocess.run(
            ["gcc", "-o", "compiler.exe", "Parser.tab.c", "lex.yy.c", "symbol_table.c", "quadruple.c", "-lm"],
            check=True,
            cwd=FLEX_BISON_DIR,
        )
        return "Make process completed successfully."
    except subprocess.CalledProcessError as e:
        return f"Error during make: {e}"

def run_compile(input_file):
    try:
        # Run the compiler executable with the uploaded file
        process = subprocess.run(
            ["compiler.exe", input_file],
            cwd=FLEX_BISON_DIR,
            text=True,
            capture_output=True,
        )
        return process.stdout or process.stderr
    except Exception as e:
        return f"Error during compile: {e}"

# Streamlit UI
st.title("Not C++!")
st.write("This is a simple compiler for a subset of the C language.")
st.write("Streamlit Coding Editor and Compiler.")
st.markdown("---")

# Initialize session state for the working file and its content
if "uploaded_file" not in st.session_state:
    st.session_state.uploaded_file = None
if "working_file_path" not in st.session_state:
    st.session_state.working_file_path = None

# File Upload and Editing
uploaded_file = st.file_uploader("Upload a file", type=["txt", "c"])
if uploaded_file:
    print(f"session_state: {st.session_state}")
    if st.session_state.uploaded_file is None or uploaded_file.name != st.session_state.uploaded_file.name:
        working_file_path = save_uploaded_file(uploaded_file)
        st.session_state.uploaded_file = uploaded_file
        st.session_state.working_file_path = working_file_path
    else:
        working_file_path = st.session_state.working_file_path

    file_name = st.session_state.uploaded_file.name

    print(f"Working file path: {working_file_path}")
    # Load file content
    with open(working_file_path, "r") as f:
        content = f.read()

    st.markdown("---")

    # Monaco editor for file content
    st.write(f"Editing file: {file_name}")
    edited_content = st_monaco(
        value=content,
        language="c",
        theme="vs-dark",  # Dark theme for better visibility
        height=400,
    )

    # Save file and actions in one row
    col1, col2, col3 = st.columns(3)

    if st.button("Save File"):
        save_edited_file(working_file_path, edited_content)

    if st.button("Make"):
        make_output = run_make()
        st.text(make_output)

    if st.button("Compile"):
        compile_output = run_compile(working_file_path)
        st.text("Compilation Output:")
        st.text(compile_output)
else:
    # Reset session state if no file is uploaded or the uploaded file is removed
    st.session_state.uploaded_file = None
    st.session_state.working_file_path = None
    print(f"session_state: {st.session_state}")