import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    private static String HEADQUARTER_RED = "red";
    private static String HEADQUARTER_BLUE = "blue";

    private static String WARRIOR_NAME_DRAGON = "dragon";
    private static String WARRIOR_NAME_NINJA = "ninja";
    private static String WARRIOR_NAME_ICEMAN = "iceman";
    private static String WARRIOR_NAME_LION = "lion";
    private static String WARRIOR_NAME_WOLF = "wolf";

    private static final String[] INPUT_ORDER = {WARRIOR_NAME_DRAGON, WARRIOR_NAME_NINJA, WARRIOR_NAME_ICEMAN, WARRIOR_NAME_LION, WARRIOR_NAME_WOLF};
    private static final String[] RED_ORDER = {WARRIOR_NAME_ICEMAN, WARRIOR_NAME_LION, WARRIOR_NAME_WOLF, WARRIOR_NAME_NINJA, WARRIOR_NAME_DRAGON};
    private static final String[] BLUE_ORDER = {WARRIOR_NAME_LION, WARRIOR_NAME_DRAGON, WARRIOR_NAME_NINJA, WARRIOR_NAME_ICEMAN, WARRIOR_NAME_WOLF};

    public static void main(String[] args) {
        int rounds; // 轮数
        int[] totalStrengthArray; // 每轮各司令部的总生命值
        int[][] allStrengthArray; // 每轮各种武士的生命值

        Scanner sc = new Scanner(System.in);
        rounds = sc.nextInt();
        totalStrengthArray = new int[rounds];
        allStrengthArray = new int[rounds][5];
        for (int i = 0; i < rounds; i++) {
            totalStrengthArray[i] = sc.nextInt();
            for (int j = 0; j < 5; j++) {
                allStrengthArray[i][j] = sc.nextInt();
            }
        }

        for (int i = 0; i < rounds; i++) {
            int[] strengthArray = allStrengthArray[i];
            Map<String, Integer> warriorStrengthMap = new HashMap<>();
            for (int j = 0; j < INPUT_ORDER.length; j++) {
                warriorStrengthMap.put(INPUT_ORDER[j], strengthArray[j]);
            }

            int totalStrength = totalStrengthArray[i];
            Headquarter redHeadquarter = new Headquarter(HEADQUARTER_RED, totalStrength, RED_ORDER);
            redHeadquarter.setActive(true); // 假定红方能生产武士
            for (int strength : strengthArray) {
                if (redHeadquarter.getTotalStrength() < strength) {
                    redHeadquarter.setActive(false);
                    break;
                }
            }

            Headquarter blueHeadquarter = new Headquarter(HEADQUARTER_BLUE, totalStrength, BLUE_ORDER);
            blueHeadquarter.setActive(true); // 假定蓝方能生成武士
            for (int strength : strengthArray) {
                if (blueHeadquarter.getTotalStrength() < strength) {
                    blueHeadquarter.setActive(false);
                    break;
                }
            }

            System.out.println("Case: " + (i + 1));
            int hours = 0;
            int indexRed = 0;
            int indexBlue = 0;
            while (redHeadquarter.isActive() || blueHeadquarter.isActive()) {
                if (redHeadquarter.isActive()) {
                    for (int j = 0; j < 5; j++) {
                        int tempIndex = (j + indexRed) % 5;
                        if (redHeadquarter.getTotalStrength() > warriorStrengthMap.get(RED_ORDER[tempIndex])) {
                            Warrior redBorn = redHeadquarter.createWarrior(RED_ORDER[indexRed], warriorStrengthMap.get(RED_ORDER[indexRed]));
                            printNewBorn(redHeadquarter, hours, redBorn);
                            indexRed = (indexRed + 1) % 5;
                            break;
                        }

                        if (j == 4) {
                            System.out.println(String.format("%03d", hours) + " " + redHeadquarter.getType() + " headquarter stops making warriors");
                            redHeadquarter.setActive(false);
                        }
                    }
                }

                if (blueHeadquarter.isActive()) {
                    for (int j = 0; j < 5; j++) {
                        int tempIndex = (j + indexBlue) % 5;
                        if (blueHeadquarter.getTotalStrength() > warriorStrengthMap.get(BLUE_ORDER[tempIndex])) {
                            Warrior blueBorn = blueHeadquarter.createWarrior(BLUE_ORDER[indexBlue], warriorStrengthMap.get(BLUE_ORDER[indexBlue]));
                            printNewBorn(blueHeadquarter, hours, blueBorn);
                            indexBlue = (indexBlue + 1) % 5;
                            break;
                        }

                        if (j == 4) {
                            System.out.println(String.format("%03d", hours) + " " + blueHeadquarter.getType() + " headquarter stops making warriors");
                            blueHeadquarter.setActive(false);
                        }
                    }
                }

                hours++;
            }
        }
    }

    private static void printNewBorn(Headquarter headquarter, int hours, Warrior redBorn) {
        System.out.println(String.format("%03d", hours) + " " + headquarter.getType() + " " + redBorn.getType() + " born with strength " + redBorn.getStrength() + "," + headquarter.getCountWarriors().get(redBorn.getType()) + " " + redBorn.getType() + " in " + headquarter.getType() + " headquarter");
    }
}
