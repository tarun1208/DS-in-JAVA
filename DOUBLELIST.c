class Node {
    int data;
    Node next;
    Node prev;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList {
    private Node head;
    private int size;

    public DoublyLinkedList() {
        this.head = null;
        this.size = 0;
    }

    // Insert at the beginning
    public void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Insert at the end
    public void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.prev = temp;
        }
        size++;
    }

    // Insert at position
    public void insertAtPosition(int data, int position) {
        if (position < 1 || position > size + 1) {
            System.out.println("Position must be >= 1 and <= " + (size + 1));
            return;
        }
        Node newNode = new Node(data);
        if (position == 1) {
            insertAtBeginning(data);
        } else {
            Node temp = head;
            for (int i = 1; i < position - 1; i++) {
                temp = temp.next;
            }
            newNode.next = temp.next;
            if (temp.next != null) {
                temp.next.prev = newNode;
            }
            temp.next = newNode;
            newNode.prev = temp;
        }
        size++;
    }

    // Delete at the beginning
    public void deleteAtBeginning() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        if (head.next == null) {
            head = null;
        } else {
            head = head.next;
            head.prev = null;
        }
        size--;
    }

    // Delete at the end
    public void deleteAtEnd() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        if (head.next == null) {
            head = null;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.prev.next = null;
        }
        size--;
    }

    // Delete at position
    public void deleteAtPosition(int position) {
        if (position < 1 || position > size) {
            System.out.println("Position must be >= 1 and <= " + size);
            return;
        }
        if (position == 1) {
            deleteAtBeginning();
        } else {
            Node temp = head;
            for (int i = 1; i < position; i++) {
                temp = temp.next;
            }
            if (temp.next != null) {
                temp.next.prev = temp.prev;
            }
            if (temp.prev != null) {
                temp.prev.next = temp.next;
            }
        }
        size--;
    }

    // Search
    public boolean search(int key) {
        Node temp = head;
        while (temp != null) {
            if (temp.data == key) {
                return true;
            }
            temp = temp.next;
        }
        return false;
    }

    // Display from beginning
    public void displayFromBeginning() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " <-> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    // Display
    public void displayFromEnd() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        while (temp != null) {
            System.out.print(temp.data + " <-> ");
            temp = temp.prev;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        DoublyLinkedList list = new DoublyLinkedList();
        list.insertAtBeginning(10);
        list.insertAtEnd(20);
        list.insertAtPosition(15, 2);
        list.displayFromBeginning(); 

        list.deleteAtBeginning();
        list.displayFromBeginning(); 
        list.deleteAtEnd();
        list.displayFromBeginning(); 
        list.deleteAtPosition(1);
        list.displayFromBeginning(); 

        list.insertAtEnd(25);
        list.insertAtEnd(30);
        list.displayFromBeginning(); 
        System.out.println("Search 25: " + list.search(25));
        System.out.println("Search 40: " + list.search(40)); 

        list.displayFromEnd();
    }
}
