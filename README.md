# Sorting Algorithms Project
  This semester during our data structures and algorithm development class we were given the project of building seven different sorting algorithms for four different data sets. Each data set was 1000 elements and they were almost sorted, randomly sorted, reverse sorted and multiple duplicates within the dataset. We were given the task of figuring out which types of sorting algorithms were more efficent based on the database's structure. We tracked the time to complete sort, number of compares, and number of exchanges to determine which algorithms worked the best. 

# Delegation 
Bubble Sort - Crawford 

Quick Sort - Quinn 

Exchange Sort - Crawford

Insertion Sort - JT

Selection Sort - Matthew

Merge Sort - Ty

Heap Sort - Quinn

# Quick Sort
  How Quicksort works is it takes an array and choses a pivot point, in my example that is the first element. Then it compares it to all the items, moving them to the right of the pivotitem if smaller, and keeping them in their spot if larger. While this is happening the final location of the pivot item is being tracked and once all the elements in the array have been compared to the pivotitem it will be placed in its final location. After that it partitions the array at the pivot item and continues this action to the left and right until every item is in their final location. 

# Quick Sort Efficiency
Best Case: n(log n)

Average Case: n(log n)

Worst Case: (n^2)


<img width="485" alt="Screenshot 2024-12-23 at 7 46 03 PM" src="https://github.com/user-attachments/assets/95cd4fd7-f10f-4655-b292-af290fe6b675" />

# Heap Sort
  How Heap Sort works is you take an array and put it into a binary tree for example. Then you heapify the array making it so the largest number in the array is at the top of the binary heap. After that is done you partition the largest number to the end of the array and continues to do this until all the items are in their final position.

# Heap Sort Efficiency
Best Case: n(log n)

Average Case: n(log n)

Worst Case: n(log n)


<img width="478" alt="Screenshot 2024-12-23 at 7 42 51 PM" src="https://github.com/user-attachments/assets/b81f75da-3fcf-4ce1-9ad6-c63d0047f0b3" />

# Efficiency Data with Randomly Sorted Data
# Time to Complete:   

Selection sort: 1,215

Exchange sort: 2,194 

Bubble sort: 2,208

Insertion sort: 83 

Merge sort: 148

Quicksort: 93

Heapsort: 121

# Number of Compares:

Selection sort: 499,500

Exchange sort: 499,500

Bubble sort: 3,676

Insertion sort: 247,840

Merge sort: 8,679

Quicksort: 11,305

Heapsort: 8,113

# Number of Swaps:

Selection sort: 990

Exchange sort: 247,840

Bubble sort: 247,521

Insertion sort: 999

Merge sort: 4,391

Quicksort: 6,050

Heapsort: 122


# Reflection
  This project was my first ever group coding project. I feel that this taught me valuable lessons in team work within the coding industry. Beiing able to cordinate not only delegation of the project details, but also set meeting times to work on the project is an invaluable skill to learn early. Also something that was very new for me was the collaboration between parts of the project. Every team member not only pulled their own weight but also helped eachother building the code and working cohesively to finish the project. 
