# CIS165 Lab 7: BMI and Color Mixer

Two C++ programs that use selection statements:

- `bmi.cpp` calculates BMI from pounds and inches and classifies it.
- `color_mixer.cpp` mixes two primary colors read into `char` arrays.

## How I wrote and ran the programs

I wrote and tested both programs in OnlineGDB, one program at a time, with C++17 selected. I downloaded each final `.cpp` file and uploaded it to this repository. The final files were also compiled with the commands below (no warnings) and the test results in this README come from those final versions.

```
g++ -std=c++17 -Wall -Wextra bmi.cpp -o bmi
./bmi

g++ -std=c++17 -Wall -Wextra color_mixer.cpp -o color_mixer
./color_mixer
```

**AI use:** I used AI (Claude) to help me understand this week's concepts, to format my work, and to spot minor errors in my code. It was used for minor code corrections and formatting only. The main correction is described in the BMI test record below. Details are in `AI_REFLECTION.md`.

---

## Program 1: BMI plan

- **Inputs:** weight in pounds and height in inches, both read from the user.
- **Variables:** `double weight`, `double height`, `double bmi`.
- **Validation:** if `weight <= 0` or `height <= 0`, print an error and end the program before any calculation.
- **Calculation:** `bmi = weight * 703.0 / (height * height);` stored in `bmi` before it is displayed.
- **Output:** the BMI shown with `fixed` and `setprecision(2)`, followed by its category:
  - BMI less than 18.5: Underweight
  - BMI from 18.5 through 25.0, including both endpoints: Optimal weight
  - BMI greater than 25.0: Overweight
- **Tests:** the five required tests plus one extra (see below).

## Program 2: Color Mixer plan

- **Inputs:** two color names, read into `char` arrays with `cin >> setw(COLOR_SIZE) >> array`.
- **Variables:** `const int COLOR_SIZE = 20;`, `char color_one[COLOR_SIZE]`, `char color_two[COLOR_SIZE]`.
- **Validation:** each input must be exactly `red`, `blue`, or `yellow` (checked with `strcmp`). If either one is not, print an error.
- **Comparisons (in this order):**
  1. either input invalid: error
  2. both inputs the same: print that color
  3. red + blue in either order: purple
  4. red + yellow in either order: orange
  5. blue + yellow in either order: green
- **Output:** `Result: <color>` or an error message.
- **Tests:** the seven required tests plus one extra (see below).

---

## BMI test record

| Program/test | Inputs | Expected result | Actual result | Match or correction |
|---|---|---|---|---|
| BMI 1 | 100, 70 | 14.35, Underweight | Your BMI is 14.35 / Category: Underweight | Match |
| BMI 2 | 150, 70 | 21.52, Optimal weight | Your BMI is 21.52 / Category: Optimal weight | Match |
| BMI 3 | 200, 70 | 28.69, Overweight | Your BMI is 28.69 / Category: Overweight | Match |
| BMI 4 | 150, 0 | Error: weight and height must be positive. | **First version:** printed the error, then also printed "You are overweight" and "Your bmi is inf". **Final version:** Error: weight and height must be positive. | Correction. See "BMI correction" below. |
| BMI 5 | -150, 70 | Error: weight and height must be positive. | **First version:** printed the error, then also printed "You are underweight" and "Your bmi is -21.52". **Final version:** Error: weight and height must be positive. | Correction. See "BMI correction" below. |
| BMI 6 (extra) | 0, 70 | Error: weight and height must be positive. | Error: weight and height must be positive. | Match |

**Extra test (BMI 6):** I used a weight of exactly 0 to check that zero is rejected, not just negative numbers. The condition `weight <= 0` (not `weight < 0`) is what makes this work. BMI 4 only checks zero for height, so this checks it for weight.

### BMI correction

In my first version, the error check printed a message but did not stop the program. The BMI was also calculated before the check. For `150, 0` the program divided by zero and got `inf`. For `-150, 70` it classified a negative BMI. The lab requires the program to end before calculating BMI.

**Fix:** I moved the validation to right after the two inputs and made it `return 1;` immediately after printing the error. The calculation now comes only after the validation passes. I also changed the output order so the BMI is displayed first, followed by its category. After the fix, both error tests print only the error message, and the three valid tests are unchanged.

---

## Color Mixer test record

| Program/test | Inputs | Expected result | Actual result | Match or correction |
|---|---|---|---|---|
| Color 1 | red, blue | purple | Result: purple | Match |
| Color 2 | red, yellow | orange | Result: orange | Match |
| Color 3 | blue, yellow | green | Result: green | Match |
| Color 4 | blue, red | purple | Result: purple | Match |
| Color 5 | red, red | red | Result: red | Match |
| Color 6 | orange, blue | Error message | Error: Invalid color entered. | Match |
| Color 7 | red, orange | Error message | Error: Invalid color entered. | Match |
| Color 8 (extra) | yellow, red | orange | Result: orange | Match |

**Extra test (Color 8):** The required tests only reverse the order for red and blue. I used `yellow, red` to check that the reversed order also works for the orange mixture. I also ran `yellow, blue` (green), `blue, blue` (blue), and `yellow, yellow` (yellow), and all matched.

---

## Explanations

**1. How does the BMI formula use pounds and inches? Why is `height * height` needed?**
The formula `weight * 703.0 / (height * height)` takes weight in pounds and height in inches. The 703.0 converts those units to the metric BMI scale. BMI depends on height squared, so the height has to be multiplied by itself. In C++, `^` is a bitwise operator and not exponentiation, so `height ^ 2` would not work.

**2. How do your conditions handle exactly 18.5 and exactly 25.0? Does the order matter? How do they avoid gaps?**
The first condition is `bmi < 18.5`. An exact 18.5 is not less than 18.5, so it moves on to the next condition, `bmi <= 25.0`, which is true, so it is Optimal. An exact 25.0 also satisfies `bmi <= 25.0`, so it is Optimal too. Only a value above 25.0 reaches the final `else` and is Overweight. The order matters: if I tested `bmi <= 18.5` first, then 18.5 would be Underweight, which is wrong. Each `else if` only runs when the one before it was false, so every possible BMI falls into exactly one category and there are no gaps.

**3. Why do you check weight and height before calculating BMI?**
If height is 0, the formula divides by zero. If either value is negative, the result is meaningless (my first version printed a negative BMI and called it "underweight"). Checking first and ending the program with an error prevents both problems.

**4. Why do you classify the unrounded BMI and round only its displayed value?**
`setprecision(2)` only changes how the number is printed. The stored value in `bmi` is not changed. Classifying with the exact value means the category is based on the true BMI. For example, a BMI of 18.496 prints as 18.50 but is still correctly Underweight.

**5. What does `strcmp` return for equal text? Why is `==` not correct for character arrays?**
`strcmp` returns 0 when the two strings have the same characters. It returns a nonzero number when they differ. A character array's name acts like a pointer to its first character, so `==` compares memory addresses, not the text. Two arrays holding the same word are at different addresses, so `==` would be false. That is why I use `strcmp(color_one, "red") == 0`.

**6. How do you make each mixture work in either input order and handle two identical colors?**
Each mixture condition has two parts joined by `||`: one for each order. For example, purple is `(color_one is red and color_two is blue) || (color_one is blue and color_two is red)`. For two identical colors, I compare the two arrays with `strcmp(color_one, color_two) == 0`. That check comes after the validity check, so it only runs on valid colors, and it comes before the mixing checks so it takes priority.

**7. How do you check for an invalid color in either input position?**
The first `if` checks both arrays. It is true if `color_one` is not red, blue, or yellow, or if `color_two` is not red, blue, or yellow. Because it is a single check that comes first, an invalid name in either position triggers the error, and no mixing logic runs.

**8. How do named constants and result variables make your programs easier to read and check?**
`COLOR_SIZE` is used for both arrays and both `setw` calls, so the size and input limit are set in one place and cannot get out of sync. Storing the calculation in `bmi` means the formula appears once, and the same variable is used for the category check and for the display. That makes it easy to verify the same value is used for both.

---

## Files

- `bmi.cpp`
- `color_mixer.cpp`
- `README.md`
- `AI_REFLECTION.md`
