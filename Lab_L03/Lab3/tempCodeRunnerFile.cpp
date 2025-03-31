T pivot = *start; // Choose the first element as the pivot
        T* i = start - 1;
        T* j = end + 1;

        while (true) {
            do {
                i++;
            } while (*i < pivot);

            do {
                j--;
            } while (*j > pivot);

            if (i >= j) {
                return j; // Return the split position
            }

            swap(*i, *j);
        }