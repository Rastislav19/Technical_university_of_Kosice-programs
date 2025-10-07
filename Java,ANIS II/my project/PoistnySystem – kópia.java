import java.util.*;

public class PoistnySystem {

    private List<PoistenaOsoba> PoisteneOsoby;
    private List<PoskytovatelZdravotnejStarostlivosti> PoskytovateliaZdravotnejStarostlivosti;
    private Map<PoistenaOsoba, List<ZdravotnyZaznam>> ZdravotneZaznamy;

    public PoistnySystem() {

        PoisteneOsoby = new ArrayList<>();
        PoskytovateliaZdravotnejStarostlivosti = new ArrayList<>();
        ZdravotneZaznamy = new HashMap<>();

    }

    public void pridajPoistenuOsobu(PoistenaOsoba osoba) {

            PoisteneOsoby.add(osoba);

    }

    public void pridajPoskytovatelaZdravotnejStarostlivosti(PoskytovatelZdravotnejStarostlivosti Poskytovatel) {

        PoskytovateliaZdravotnejStarostlivosti.add(Poskytovatel);

    }

    public void pridajZdravotnyZaznam(PoistenaOsoba osoba, ZdravotnyZaznam ZdravotnaSluzba) {

        if (!ZdravotneZaznamy.containsKey(osoba)) {

            ZdravotneZaznamy.put(osoba, new ArrayList<>());

        }

        List<ZdravotnyZaznam> ZdravotneSluzby = ZdravotneZaznamy.get(osoba);
        ZdravotneSluzby.add(ZdravotnaSluzba);

    }

    public void printSpravyZdravotnehoStavu(PoistenaOsoba osoba) {

        if (ZdravotneZaznamy.containsKey(osoba)) {

            List<ZdravotnyZaznam> ZdravotneSluzby = ZdravotneZaznamy.get(osoba);
            System.out.println("Zdravotné služby pre osobu " + osoba.getMeno() + "("+ osoba.getVek()+")" + ":");

            for (ZdravotnyZaznam ZdravotnaSluzba : ZdravotneSluzby) {

                System.out.println(" -- " + ZdravotnaSluzba.getSluzba() + ", cena: " + ZdravotnaSluzba.getCena());

            }
        }
        else {

            System.out.println("Pre túto osobu nie sú evidované žiadne druhy starostlivosti.");

        }
    }
}
