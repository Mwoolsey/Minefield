# BUG LOG  
The FIELD_DIMENSION is set to 10 by default but in the function inBounds the test goes out of bounds when running on 10,10 since the vector is zero based.  
In the revealAdjacent function the logic test should have an && after the bounds check instead of an or. 
