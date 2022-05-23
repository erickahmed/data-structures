public class MainDynamicArray {
    public static void main(String[] args) {
        DynamicArray testArray = new DynamicArray();
        testArray.ArrayInit(2);

        testArray.IsEmpty();
        testArray.Debug();

        testArray.Insert(3);
        testArray.Debug();
        testArray.Insert(7);
        testArray.Debug();
        testArray.Insert(6);
        testArray.Debug();
        testArray.Insert(-2);
        testArray.Debug();

        System.out.println(testArray.BinarySearch(3));
    }
}