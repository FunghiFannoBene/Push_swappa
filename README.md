# Push_swappa Algorithm for Chunked Number Sorting

## Objective
The objective of this algorithm is to sort 100 numbers in the range of 500-600 using the Push_swappa method. 
It employs a divide and conquer approach, creating a V shape pattern with a sequence of 
"Big Medium Small Medium Big." The algorithm ensures an ascending order for stack A while maintaining 
the desired pattern and pushing any larger numbers to stack B.

## Algorithm Steps

1. **Divide and Conquer**
   - Split the numbers into chunks.
   - Half of each chunk goes to stack B.
   - The other half is further divided into "pb" and "rb" segments.

2. **Increment Chunk Size**
   - Increase the chunk size by (3/4) of the previous chunk.
   - Each chunk will contain approximately 15 numbers.

3. **Repeat the Process**
   - Continue the process until the chunk size reaches a minimum of 93.
   - Generate random results between the segments.
   - Example: "(21-28) (1-10)" (TOP B) and "(11-20) (29-35)" (BOTTOM B).

4. **Ascending Order in Stack A**
   - If the head of stack A is 100, start the ascending order.
   - Push the numbers in ascending order while maintaining the pattern.
   - Example: 100 88 86 82 83 89 90 99 becomes 100 88 89 80 99.
   - Numbers larger than the tail of stack A are pushed using "rb" or "rrb" operations.

## Usage
To use this algorithm, follow these steps:
1. Prepare a stack A with 100 numbers in the range of 500-600.
2. Ensure that 100 is at the head of stack A.
3. Execute the Push_swappa algorithm, adhering to the steps mentioned above.
4. Verify the output stacks A and B for the sorted numbers.

Feel free to contribute to this algorithm and improve its efficiency!

![Algorithm Flowchart](link_to_flowchart_image)
