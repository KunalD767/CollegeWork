// Package music
package music;

public interface Playable {
    void play();
}

// Package music.string
package music.string;

import music.Playable;

public class Veena implements Playable {
    public void play() {
        System.out.println("Veena is playing");
    }
}

// Package music.wind
package music.wind;

import music.Playable;

public class Saxophone implements Playable {
    public void play() {
        System.out.println("Saxophone is playing");
    }
}

// Package live
package live;

import music.Playable;
import music.string.Veena;
import music.wind.Saxophone;

public class Test {
    public static void main(String[] args) {
        Veena veena = new Veena();
        veena.play();

        Saxophone saxophone = new Saxophone();
        saxophone.play();

        Playable playable1 = veena;
        playable1.play();

        Playable playable2 = saxophone;
        playable2.play();
    }
}
