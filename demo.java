import java.util.*;

class M {
    public void show() throws Exception {
        throw new Exception("Error Thrown");
    }
}

class demo {

    public static void main(String args[]) {
        try {
            M hero = new M();
            hero.show();
        } catch (Exception e) {
            System.out.println("Error Found in M object");
        }
    }
}