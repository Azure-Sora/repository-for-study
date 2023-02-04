package ClassLearning.FightingGame;

import java.util.Random;

public class Character {
    private String name;
    private int health = 100;

    public Character() {
    }

    public Character(String name, int health) {
        this.name = name;
        this.health = health;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getHealth() {
        return health;
    }

    public void setHealth(int health) {
        this.health = health;
    }

    public int fight() {
        Random random = new Random();
        int damage = random.nextInt(20);
        System.out.print(this.name + "举起拳头打了");
        return damage;
    }

    public boolean injure(int damage) {
        this.health -= damage;
        if (this.health < 0) {
            setHealth(0);
        }
        System.out.print(this.name + "一下，造成了" + damage + "点伤害，" + this.name + "还剩下" + this.health + "点血\n");
        return this.health <= 0;
    }
}
