@echo off
git add .
git status .

:Input
SET /p @comment="Enter a comment for the commitment: "
if "%@comment%" == "" (
    goto :Input
)

:GitCommit
git commit -m "%@comment%"
git push origin master
echo Complete
Pause