public class Person {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    void hello(Person p) {
        System.out.println("Hello, " + p.getName() + "!");
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public static void main(String[] args) {
        Person p = new Person("Chen", 5);
        p.hello(p);
        System.out.println("(He is " + p.getAge() + " years old.)");
    }
}
