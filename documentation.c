/*
while (i<6) {
    some code
}
---->
label1:
if i>=6 goto label2
some code
goto label1
label2:
*/

/*
//switch case
switch (i) {
    case 1:
        some code
        break;
    case 2:
        some code
        break;
    default:
        some code
        break;
}
---->
if i==1 goto label1
if i==2 goto label2
goto label3
label1:
if i!=1 goto label2
some code
goto label4
label2:
if i!=2 goto label3
some code
goto label4
label3:
some code
label4:
*/

/*
for loop
if  i>=6 goto label2
label1: 
some code
if (i<6) goto label1
label2:
*/
/* 
repeat {
    some code
} until (i<6)
---->
label1:
some code
if i<6 goto label1

*/
/*
if (i>=6) {
    some code
} else {
    some code
} 
---->
if i>=6 goto label1
some code
goto label2
label1:
some code
label2:
*/
// MATCHED_IF: 
//     IF LPAREN FINAL_EXP RPAREN LBRACE MATCHED_IF RBRACE ELSE LBRACE MATCHED_IF RBRACE
//     {

      
//     }
//   | STMTS
//     {
       
//     }
// ;

/*
if (i>=6) {
    some code1
}
else {
    some code2
}
---->

if i>=6 goto label1
some code2
goto label2
label1:
some code1
label2:
*/

/*
unmatched if  
if (i>=6) {
    some code
}
---->
if i>=6 goto label1
goto label2
label1:
some code
label2:
*/
/*
if i>=6 goto label1
some code2
goto label2
label1:
some code1
label2:
*/