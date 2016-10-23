public class Warrior {
    // 武士编号
    private int number;
    // 武士类型
    private String type;
    // 武士的初始生命值，其实就是「力量」
    private int strength;

    public Warrior(String type, int strength) {
        this.type = type;
        this.strength = strength;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getStrength() {
        return strength;
    }

    public void setStrength(int strength) {
        this.strength = strength;
    }
}
