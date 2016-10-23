import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Headquarter {
    private String type;
    private int totalStrength;
    private String[] warriorNameArray;
    private List<Warrior> warriorList;
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

    Warrior createWarrior(String type, int life) {
        if (this.totalStrength > life) {
            Warrior warrior = new Warrior(type, life);

            this.warriorList.add(warrior);
            this.totalStrength -= life;
            this.countWarriors.put(type, this.countWarriors.get(type) + 1);
            return warrior;
        } else {
            return null;
        }
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getTotalStrength() {
        return totalStrength;
    }

    public void setTotalStrength(int totalStrength) {
        this.totalStrength = totalStrength;
    }

    public String[] getWarriorNameArray() {
        return warriorNameArray;
    }

    public void setWarriorNameArray(String[] warriorNameArray) {
        this.warriorNameArray = warriorNameArray;
    }

    public List<Warrior> getWarriorList() {
        return warriorList;
    }

    public void setWarriorList(List<Warrior> warriorList) {
        this.warriorList = warriorList;
    }

    public Map<String, Integer> getCountWarriors() {
        return countWarriors;
    }

    public void setCountWarriors(Map<String, Integer> countWarriors) {
        this.countWarriors = countWarriors;
    }

    public boolean isActive() {
        return active;
    }

    public void setActive(boolean active) {
        this.active = active;
    }
}
