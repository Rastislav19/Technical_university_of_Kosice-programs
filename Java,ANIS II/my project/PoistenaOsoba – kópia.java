import java.util.Objects;

public class PoistenaOsoba extends Osoby {
    private String CisloPoistenia;

    public PoistenaOsoba(String meno, int vek, String CisloPoistenia) {

        super(meno, vek);
        this.CisloPoistenia = CisloPoistenia;

    }

    public PoistenaOsoba(String meno, int vek) {

        super(meno, vek);

    }

    public String getCisloPoistenia() {

        return CisloPoistenia;

    }

    @Override
    public boolean equals(Object obj) {

        if (this == obj) {

            return true;

        }

        if ( getClass() != obj.getClass() || obj == null ) {

            return false;

        }

        PoistenaOsoba osoba = (PoistenaOsoba) obj;
        return CisloPoistenia.equals(osoba.CisloPoistenia);
    }

    @Override
    public int hashCode() {
        return Objects.hash(CisloPoistenia);
    }
}

