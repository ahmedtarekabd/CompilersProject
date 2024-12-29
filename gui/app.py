import streamlit as st
import subprocess
import os

# Define working directory as the current directory of the script
WORK_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def save_uploaded_file(uploaded_file):
    file_path = os.path.join(WORK_DIR, uploaded_file.name)
    with open(file_path, "wb") as f:
        f.write(uploaded_file.getbuffer())
    return file_path

def run_make():
    try:
        print("Running make process...")
        # Run flex and bison commands
        subprocess.run(["flex", "Lexer.l"], check=True, cwd=WORK_DIR)
        subprocess.run(["bison", "-d", "Parser.y"], check=True, cwd=WORK_DIR)
        # Compile generated C files into compiler.exe
        subprocess.run(
            ["gcc", "-o", "compiler.exe", "Parser.tab.c", "lex.yy.c", "symbol_table.c", "quadruple.c", "-lm"],
            check=True,
            cwd=WORK_DIR
        )
        return "Make process completed successfully."
    except subprocess.CalledProcessError as e:
        return f"Error during make: {e}"

def run_compile(input_file):
    try:
        print(f"Running compile process for '{input_file}'...")
        # Run the compiler executable with the uploaded file
        process = subprocess.run(
            [os.path.join(WORK_DIR, "compiler.exe"), input_file],
            cwd=WORK_DIR,
            text=True,
            capture_output=True,
        )
        return process.stdout or process.stderr
    except Exception as e:
        return f"Error during compile: {e}"

# Streamlit UI
st.title("Streamlit Text Editor and Compiler")

# File Upload and Preview
uploaded_file = st.file_uploader("Upload a file", type=["txt", "c"])
if uploaded_file:
    file_path = save_uploaded_file(uploaded_file)
    st.write(f"Preview of {uploaded_file.name}:")
    with open(file_path, "r") as f:
        content = f.read()
    st.text_area("File Content", content, height=300)

    # Buttons for Make and Compile
    if st.button("Make"):
        make_output = run_make()
        st.text(make_output)

    if st.button("Compile"):
        compile_output = run_compile(file_path)
        st.text("Compilation Output:")
        st.text(compile_output)
