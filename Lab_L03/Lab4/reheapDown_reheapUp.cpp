void reheapDown(int maxHeap[], int numberOfElements, int index) {
    int largest = index; // Assume the current index is the largest
    int leftChild = 2 * index + 1; // Left child index
    int rightChild = 2 * index + 2; // Right child index

    // Check if the left child exists and is greater than the current largest
    if (leftChild < numberOfElements && maxHeap[leftChild] > maxHeap[largest]) {
        largest = leftChild;
    }

    // Check if the right child exists and is greater than the current largest
    if (rightChild < numberOfElements && maxHeap[rightChild] > maxHeap[largest]) {
        largest = rightChild;
    }

    // If the largest is not the current index, swap and continue heapifying
    if (largest != index) {
        std::swap(maxHeap[index], maxHeap[largest]);
        reheapDown(maxHeap, numberOfElements, largest); // Recursively heapify the affected subtree
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index) {
    int parent = (index - 1) / 2; // Calculate the parent index

    // While the current node is not the root and is greater than its parent
    while (index > 0 && maxHeap[index] > maxHeap[parent]) {
        std::swap(maxHeap[index], maxHeap[parent]); // Swap the current node with its parent
        index = parent; // Move up to the parent
        parent = (index - 1) / 2; // Recalculate the parent index
    }
}