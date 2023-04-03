class Node{
    public int data;
    public Node next;
    public Node(int data) {
        this.data=data;
    }
   


}

public class Linkedlist {
    private Node head;

    public void append(int data){
        if (head == null){
            head = new Node(data);
            return;
        }
        Node temp = head;
        while(temp.next != null){
            temp = temp.next;
        }
        temp.next = new Node(data);
    }

    public void prepend(int data) {
        if (head == null){
            head = new Node(data);
            return;
        }
        Node temp = head;
        head = new Node(data);
        head.next = temp;

    }

    public void delWithValue(int data){
        if(head == null){
            System.out.println("nothing to delete");
            return;
        }
        if (head.data == data){
            head = head.next;
            return;
        }
        Node temp = head;
        while (temp.next != null){
            if(temp.next.data == data){
                temp.next = temp.next.next;
                return;
            }
            temp = temp.next;
        }
        System.out.println("no such value");

    }

    public void traverse(){
        Node temp = head;
        while (temp != null){
            System.out.println(temp.data);
            temp = temp.next;
        }
        
    }

}
