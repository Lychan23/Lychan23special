package games.snake;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SnakeGame extends JFrame implements ActionListener {
    private static final int SCALE = 10;
    private static final int WIDTH = 40;
    private static final int HEIGHT = 30;
    private static final int DELAY = 100;

    private int appleX;
    private int appleY;
    private int[] snakeX;
    private int[] snakeY;
    private int snakeSize;
    private boolean gameover;
    private String direction;

    private Timer timer;

    public SnakeGame() {
        setTitle("Snake Game");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(WIDTH * SCALE, HEIGHT * SCALE);
        setResizable(false);
        setLocationRelativeTo(null);

        snakeX = new int[WIDTH * HEIGHT];
        snakeY = new int[WIDTH * HEIGHT];
        snakeSize = 3;
        direction = "RIGHT";
        gameover = false;

        addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                int key = e.getKeyCode();
                if (key == KeyEvent.VK_UP && !direction.equals("DOWN")) {
                    direction = "UP";
                } else if (key == KeyEvent.VK_DOWN && !direction.equals("UP")) {
                    direction = "DOWN";
                } else if (key == KeyEvent.VK_LEFT && !direction.equals("RIGHT")) {
                    direction = "LEFT";
                } else if (key == KeyEvent.VK_RIGHT && !direction.equals("LEFT")) {
                    direction = "RIGHT";
                }
            }
        });

        timer = new Timer(DELAY, this);
        timer.start();

        createApple();

        setVisible(true);
    }

    public void createApple() {
        appleX = (int) (Math.random() * WIDTH) * SCALE;
        appleY = (int) (Math.random() * HEIGHT) * SCALE;
    }

    public void move() {
        for (int i = snakeSize; i > 0; i--) {
            snakeX[i] = snakeX[i - 1];
            snakeY[i] = snakeY[i - 1];
        }

        if (direction.equals("UP")) {
            snakeY[0] -= SCALE;
        } else if (direction.equals("DOWN")) {
            snakeY[0] += SCALE;
        } else if (direction.equals("LEFT")) {
            snakeX[0] -= SCALE;
        } else if (direction.equals("RIGHT")) {
            snakeX[0] += SCALE;
        }
    }

    public void checkCollision() {
        if (snakeX[0] < 0 || snakeX[0] >= WIDTH * SCALE || snakeY[0] < 0 || snakeY[0] >= HEIGHT * SCALE) {
            gameover = true;
        }

        for (int i = 1; i < snakeSize; i++) {
            if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
                gameover = true;
            }
        }

        if (snakeX[0] == appleX && snakeY[0] == appleY) {
            snakeSize++;
            createApple();
        }
    }

    @Override
    public void paint(Graphics g) {
        g.setColor(Color.black);
        g.fillRect(0, 0, WIDTH * SCALE, HEIGHT * SCALE);

        if (!gameover) {
            g.setColor(Color.red);
            g.fillRect(appleX, appleY, SCALE, SCALE);

            g.setColor(Color.green);
            for (int i = 0; i < snakeSize; i++) {
                g.fillRect(snakeX[i], snakeY[i], SCALE, SCALE);
            }
        } else {
            g.setColor(Color.white);
            g.setFont(new Font("Arial", Font.BOLD, 20));
            g.drawString("Game Over", WIDTH * SCALE / 2 - 60, HEIGHT * SCALE / 2);
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (!gameover) {
            move();
            checkCollision();
        }

        repaint();
    }

    public static void main(String[] args) {
        new SnakeGame();
    }
}
