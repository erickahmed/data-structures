public class MainDLL {
    public static void main(String[] args) {
        DoublyLinkedList testList = new DoublyLinkedList();

        testList.IsEmpty();
        testList.Debug();

        testList.InsertFirst(3);
        testList.Debug();
        testList.InsertAtIndex(1, 7);
        testList.Debug();
        testList.InsertLast(6);
        testList.Debug();
        testList.RemoveAtIndex(0);
        testList.Debug();

    }
}
