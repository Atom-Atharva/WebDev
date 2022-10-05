class A {
    A() {
        System.out.println("IN A");
    }

    A(int i) {
        System.out.println("IN Parameter A");
    }
}

class B extends A {
    B() {
        System.out.println("IN B");
    }

    B(int i) {
        System.out.println("IN Parameter B");
    }
}

public class Super {
    public static void main(String args[]) {
        B b1 = new B();
        B b2 = new B(5);
    }
}