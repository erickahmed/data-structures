import java.util.Iterator;
import java.util.function.Consumer;

public class DynamicArray implements Iterable<Integer> {
    public int SIZEOFINT= 4;

    public int[] arr;
    public int len  = 0;
    private int cap = SIZEOFINT;

    // Array initialization
    public void ArrayInit(int capacity) {
        if(capacity < 0) throw new IllegalArgumentException("Capacity cannot be negative!");
        this.cap = capacity;
        arr = new int[cap];
    }

    // Given a static array make it dynamic
    public void ArrayInit(int[] array) {
        if(array.equals(null)) throw new IllegalArgumentException("Array cannot be null!");
        arr = java.util.Arrays.copyOf(array, array.length);
        cap = len = array.length;
    }

    // Get value at specific index
    public int Get(int index) {
        return arr[index];
    }

    // Set a value at specific index
    public void Set(int index, int elem) {
        arr[index] = elem;
    }

    // Insert element at first free space and eventually change array dimension dynamically
    public void Insert(int elem) {
        if (len + 1 >= cap) {
            if (cap == 0) cap = 1;
            else cap *= 2;
        } else if (len + 1 <= (cap/2)) cap /= 2;

        arr = java.util.Arrays.copyOf(arr, cap);
        arr[len++] = elem;
    }

    // Remove element at specific index
    public void RemoveAtIndex(int index) {
        System.arraycopy(arr, index + 1, arr, index, len - (index - 1));
        --len;
        --cap;
    }

    // Remove a specific element at any index
    public boolean RemoveElem(int elem) {
        for (int i = 0; i < len; i++) {
            if(arr[i] == elem) {
                RemoveAtIndex(i);
                return true;
            }
        }
        return false;
    }

    // Return array size
    public int Size() {
        return len;
    }

    public boolean IsEmpty() {
        return len == 0;
    }

    public boolean IsFull() {
        return len == cap;
    }

    public int BinarySearch(int key) {
        int index = java.util.Arrays.binarySearch(arr, 0, len, key);
        return index;
    }

    public void Sort() {
        java.util.Arrays.sort(arr, 0, len);
    }

    public void Debug() {
        if (len == 0) System.out.println("[]");
        else {
            System.out.print("[");
            for (int i = 0; i < len - 1; i++) System.out.print(arr[i] + ", ");
            System.out.println(arr[len - 1] + "]");
            System.out.println();
        }
    }

    @Override
    public Iterator<Integer> iterator() {
        return new Iterator<Integer>() {
            @Override
            public boolean hasNext() {
                return false;
            }

            @Override
            public Integer next() {
                return null;
            }

            @Override
            public void remove() {
                Iterator.super.remove();
            }

            @Override
            public void forEachRemaining(Consumer<? super Integer> action) {
                Iterator.super.forEachRemaining(action);
            }
        };
    }
}

