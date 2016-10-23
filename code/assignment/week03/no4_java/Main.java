import java.util.HashMap;
import java.util.Map;

public class Main {
    private static String SQUARTER_RED = "red";
    private static String SQUARTER_BLUE = "blue";

    private static String WARRIOR_NAME_DRAGON = "dragon";
    private static String WARRIOR_NAME_NINJA = "ninja";
    private static String WARRIOR_NAME_ICEMAN = "iceman";
    private static String WARRIOR_NAME_LION = "lion";
    private static String WARRIOR_NAME_WOLF = "wolf";

    private static final String[] INPUT_ORDER = {WARRIOR_NAME_DRAGON, WARRIOR_NAME_NINJA, WARRIOR_NAME_ICEMAN, WARRIOR_NAME_LION, WARRIOR_NAME_WOLF};
    private static final String[] RED_ORDER = {WARRIOR_NAME_ICEMAN, WARRIOR_NAME_LION, WARRIOR_NAME_WOLF, WARRIOR_NAME_NINJA, WARRIOR_NAME_DRAGON};
    private static final String[] BLUE_ORDER = {WARRIOR_NAME_LION, WARRIOR_NAME_DRAGON, WARRIOR_NAME_NINJA, WARRIOR_NAME_ICEMAN, WARRIOR_NAME_WOLF};

    public static void main(String[] args) {
        int rounds = 1;
        int[] totalLifeArray = {20};
        int[][] allLifeArray = {{3, 4, 5, 6, 7}};

        for (int i = 0; i < rounds; i++) {
            int[] lifeArray = allLifeArray[i];
            Map<String, Integer> warriorStrengthMap = new HashMap();
            for (int j = 0; j < INPUT_ORDER.length; j++) {
                warriorStrengthMap.put(INPUT_ORDER[j], lifeArray[j]);
            }

            int totalLife = totalLifeArray[i];
            Headquarter redSquarter = new Headquarter(SQUARTER_RED, totalLife, RED_ORDER);
            redSquarter.setActive(true); // 假定红方能生产武士
            for (int strength : lifeArray) {
                if (redSquarter.getTotalStrength() < strength) {
                    redSquarter.setActive(false);
                    break;
                }
            }

            Headquarter blueSquarter = new Headquarter(SQUARTER_BLUE, totalLife, BLUE_ORDER);
            blueSquarter.setActive(true); // 假定蓝方能生成武士
            for (int strength : lifeArray) {
                if (blueSquarter.getTotalStrength() < strength) {
                    blueSquarter.setActive(false);
                    break;
                }
            }

            System.out.println("Case: " + (i + 1));
            int hours = 0;
            int indexRed = 0;
            int indexBlue = 0;
            while (redSquarter.isActive() || blueSquarter.isActive()) {
                Warrior redBorn;
                if (redSquarter.isActive()) {
                    redBorn = redSquarter.createWarrior(RED_ORDER[indexRed], warriorStrengthMap.get(RED_ORDER[indexRed]));
                    if (null != redBorn) {
                        printNewBorn(redSquarter, hours, redBorn);
                    } else {
                        while (redSquarter.isActive()) {
                            for (int j = 0; j < 5; j++) {
                                int tempIndex = (j + indexRed + 1) % 5;
                                redBorn = redSquarter.createWarrior(RED_ORDER[tempIndex], warriorStrengthMap.get(RED_ORDER[tempIndex]));
                                if (redBorn != null) {
                                    break;
                                }

                                if (j == 4) {
                                    System.out.println(hours + " " + redSquarter.getType() + " headquarter stops making warriors");
                                    redSquarter.setActive(false);
                                }
                            }
                        }
                    }
                    indexRed++;
                }

                Warrior blueBorn;
                if (blueSquarter.isActive()) {
                    blueBorn = blueSquarter.createWarrior(BLUE_ORDER[indexBlue], warriorStrengthMap.get(BLUE_ORDER[indexBlue]));
                    if (null != blueBorn) {
                        printNewBorn(blueSquarter, hours, blueBorn);
                    } else {
                        while (blueSquarter.isActive()) {
                            for (int j = 0; j < 5; j++) {
                                int tempIndex = (j + indexRed + 1) % 5;
                                redBorn = blueSquarter.createWarrior(RED_ORDER[tempIndex], warriorStrengthMap.get(RED_ORDER[tempIndex]));
                                if (redBorn != null) {
                                    break;
                                }

                                if (j == 4) {
                                    System.out.println(hours + " " + blueSquarter.getType() + " headquarter stops making warriors");
                                    blueSquarter.setActive(false);
                                }
                            }
                        }
                    }
                    indexBlue++;
                }

                hours++;
            }
        }
    }

    private static void printNewBorn(Headquarter redSquarter, int hours, Warrior redBorn) {
        System.out.println(hours + " " + SQUARTER_RED + " " + redBorn.getType() + " born with strength " + redBorn.getStrength() + "," + redSquarter.getCountWarriors().get(redBorn.getType()) + " " + redBorn.getType() + " in " + SQUARTER_RED + " headquarter");
    }
}
