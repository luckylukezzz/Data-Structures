public class Main {
    public static void main(String[] args) {
        Linkedlist x = new Linkedlist();
        x.append(5);
        x.append(6);
        x.append(7);
        x.prepend(1);
        x.append(8);
        x.delWithValue(5);
        x.traverse();   
    }
}
