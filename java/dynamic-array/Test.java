public class Test {
    public static void main(String[] args) {
        DynamicArray testArray = new DynamicArray();
        testArray.ArrayInit(2);

        testArray.IsEmpty();

        testArray.Insert(3);
        testArray.Insert(7);
        testArray.Insert(6);
        testArray.Insert(-2);

        testArray.BinarySearch(3);

        testArray.Debug();
    }
}