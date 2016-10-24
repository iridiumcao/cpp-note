public class Warrior {
    // 武士类型
    private String type;
    // 武士的初始生命值，其实就是「力量」
    private int strength;

    public Warrior(String type, int strength) {
        this.type = type;
        this.strength = strength;
    }

    public String getType() {
        return type;
    }

    public int getStrength() {
        return strength;
    }
}
