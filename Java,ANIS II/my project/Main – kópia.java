public class Main {
    public static void main(String[] args) {

        PoistnySystem system = new PoistnySystem();

        PoistenaOsoba osoba1 = new PoistenaOsoba("Janko Mrkvička", 21, "0001");
        system.pridajPoistenuOsobu(osoba1);

        PoskytovatelZdravotnejStarostlivosti poskytovatel1 = new PoskytovatelZdravotnejStarostlivosti("UNION", 2013, "Un10N");
        system.pridajPoskytovatelaZdravotnejStarostlivosti(poskytovatel1);

        ZdravotnyZaznam druhStarostlivosti1 = new ZdravotnyZaznam("zubár", 200.0);
        ZdravotnyZaznam druhStarostlivosti2 = new ZdravotnyZaznam("rehabilitácia", 150.0);
        system.pridajZdravotnyZaznam(osoba1,druhStarostlivosti1);
        system.pridajZdravotnyZaznam(osoba1,druhStarostlivosti2);

        system.printSpravyZdravotnehoStavu(osoba1);
    }
}
