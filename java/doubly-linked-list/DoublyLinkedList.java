import java.util.Iterator;
import java.util.function.Consumer;

public class DoublyLinkedList<T> implements Iterable<T> {
    private int size = 0;
    private NODE <T> head = null;
    private NODE <T> tail = null;

    @Override
    public Iterator<T> iterator() {return null;}
}
/* Internal class to define data */
class Node <T> {
    T data;
    Node <T> prev;
    T next;

    public Node (T data, Node <T> prev, Node <T> next) {
        this.data = data;
        this.prev = prev;
        this.next = next;
    }
    @Override public String toString() {
        return data.toString();
    }
}

public Node<T> SearchAt(int index) {
    Node <T> trav = head;
    while (trav < index) {
        Node<T> next = trav.next;
    }
    return trav;
}

/* Adds an element to a specific index of the list, time complexity O(n) */
public int InsertAtIndex(int index, T elem) {
    switch (index) {
        case (index < 0 || index >= size):
            throw new IllegalArgumentException("Index out of bounds!");
            return 1;
            break;
        case (IsEmpty()):
            head = tail = new Node<T>(elem, null, null);
            break;
        case (index == 0):
            head.prev = new Node <T> (elem, null, head);
            head = head.prev;
            break;
        case (index == size):
            tail.next = new Node <T> (elem, tail, null);
            tail = tail.next;
            break;
        default:
            trav = SearchAt(index);
            if (trav == index) {
                head.prev = new Node<T>(elem, tail, head);
                head.next = new Node<T>(elem, tail, head);
            }
            trav = next;
        }
        break;
    }
    size++;
}

/* Adds an element to the first index of the list, time complexity O(1) */
public int InsertFirst(int elem) {
    InsertAtIndex(0, elem);
}

/* Adds an element to the last index of the list, time complexity O(1) */
public int InsertLast(int elem) {
    InsertAtIndex(size, elem);
}

/* Deallocates every element, time complexity O(n) */
public void Clear() {
    Node <T> trav = head;
    while (trav != null) {
        Node <T> next = trav.next;
        trav.prev = trav.next = trav.data = null;
        trav = next;
    }
    head = tail = trav = null;
    size = 0;
}

/* Removes an element at a specific index of the list, time complexity O(n) */
public int RemoveAtIndex(int index) {
    switch(index) {
        case(index < 0 || index >= size):
            throw new IllegalArgumentException("Index out of bounds!");
            return 1;
            break;
        case(IsEmpty()):
            throw new RuntimeException("List is empty");
            head = tail = null;
            break;
        case(index == 0):
            T data = head.data;

            head = head.next
            --size;
            head.prev == null;
            return data;
            break;
        case(index == size):
            T data = tail.data;

            tail = tail.prev
            --size;
            tail.next == null;
            return data;
            break;
        default:
            Node <T> trav;

            /* Linear search */
            if (index < (size / 2)) {
                for (int i = 0, trav = head; i != index; i++)
                    trav = trav.next;
            } else {
                for (int i = --size, trav = tail; i != index; i--)
                    trav = trav.prev;
            }

            trav.next.prev = trav.prev;
            trav.prev.next = trav.next;
            index = index.prev = index.next = null;

            --size;

            break;
    }
}

/* Removes an element at the first index of the list, time complexity O(1) */
public int RemoveFirst() {
    RemoveAtIndex(0);
}

/* Removes an element at the last index of the list, time complexity O(1) */
public int RemoveLast() {
    RemoveAtIndex(size);
}

public int Size() {
    return size;
}

public int IsEmpty() {
    return size == 0;
}

public int IndexOf(int obj) {
    int index = 0;
    Node <T> trav = head;

    for(trav = head; trav != null; trav = trav.next, index++) {
        if(obj.equals(trav.data)) return index;
    } return -1;
}

public void Debug() {
    if (size == 0) {
        System.out.print("[]");
        System.out.println();
    }
    else {
        System.out.print("[");
        for (int i = 0; i < size - 1; i++) {
            System.out.print(trav.data + ", ")
            System.out.print(trav.data[size-1]+"]");
            System.out.println();
        }
    }
}