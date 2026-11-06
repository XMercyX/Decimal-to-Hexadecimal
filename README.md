# **Hexadecimal to Decimal Converter**
This is my first real project outside of any tutorials on YouTube.<br>
I thought it would be an easy project. <br>
Of course, I was wrong. <br>
I'm confident that I can manage though.

## GOAL:
Create a program that asks the user for hexadecimal values and outputs the decimal equivalent.
### Stretch Goals:
Make functional operations such as addition, subtraction, and multiplication.  

## Day 1:
<p>Good progress. <br>
Got some helper functions that should make development easier. </p>
### Todo:
<p>Figure out conversion<br>
Implement conversion </p>


### Future Goals:
Figure out and implement operations (+,-,*,/)


## Day 2:
  Some more functions made to help in development.
### Todo:
  Issue with the `convertToDecimal()` function that needs to be resolved.

### Examples of `convertToDecimal()` error:
  |**Input**|**Output**|**Real Value**|
  |---|---|---|
  |1|1|1|
  |a|10|10|
  |01|16|1|
  |67|118|103|
  |76|103|118|
  |aabb83|3718058|11189123|
  |38bbaa|11189123|3718058|

### Conclusion:
  The values seem to be reversed :(
  
  It's an easy fix tho.


## FIXED!
changed line 127 from `output += convertCharacterToDecimal(INPUT[i]) * (pow(16,i));` <br> <br>
to 

`output += convertCharacterToDecimal(rev[i]) * (pow(16,i));`<br>

easy fix :)