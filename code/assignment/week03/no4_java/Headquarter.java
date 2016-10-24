import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Headquarter {
    private String type;
    private int totalStrength;
    private String[] warriorNameArray;
    private List<Warrior> warriorList;
    // 各种武士对应的数量
    private Map<String, Integer> countWarriors;
    // 是否还能制造武士
    private boolean active;

    public Headquarter(String type, int totalStrength, String[] warriorNameArray) {
        this.type = type;
        this.totalStrength = totalStrength;
        this.warriorNameArray = warriorNameArray;

        warriorList = new ArrayList<>();

        this.countWarriors = new HashMap<>();
        for (String name : warriorNameArray) {
            this.countWarriors.put(name, 0);
        }

        this.active = true;
    }

    Warrior createWarrior(String type, int strength) {
        if (this.totalStrength > strength) {
            Warrior warrior = new Warrior(type, strength);

            this.warriorList.add(warrior);
            this.totalStrength -= strength;
            this.countWarriors.put(type, this.countWarriors.get(type) + 1);
            return warrior;
        } else {
            return null;
        }
    }

    public String getType() {
        return type;
    }

    public int getTotalStrength() {
        return totalStrength;
    }

    public Map<String, Integer> getCountWarriors() {
        return countWarriors;
    }

    public boolean isActive() {
        return active;
    }

    public void setActive(boolean active) {
        this.active = active;
    }
}