# AI Reflection: Lab 7

**Tools used:** I used Claude (an AI assistant) to help me understand this week's concepts, to format my work, and to spot minor errors in my code. It was used for minor code corrections and formatting only. I wrote both programs myself in OnlineGDB first.

**One decision:** The AI pointed out that my `bmi.cpp` printed an error for bad input but did not stop the program, and that BMI was calculated before the check. I accepted this correction: I moved the validation above the calculation and added `return 1;` after the error message. I kept my own `if / else if` category structure, since it already handled 18.5 and 25.0 correctly.

**Checking my work:** With my original version, input `150, 0` printed the error and then "Your bmi is inf", and `-150, 70` also printed "underweight". After the fix, both print only the error. I hand-checked the math too: 150 * 703 / (70 * 70) = 105450 / 4900 = 21.52, which matched the output. For `color_mixer.cpp`, I ran every mixture in both orders, all three same-color cases, and an invalid color in each position.

**Learning:** I can now validate input before calculating and compare character arrays with `strcmp(...) == 0` instead of `==`. I still need to practice ordering `else if` conditions so boundary values land in the right category, and writing my test predictions before I run the code.
