import java.util.Objects;

public class PoskytovatelZdravotnejStarostlivosti extends Osoby {
    private String IdPoskytovatela;

    public PoskytovatelZdravotnejStarostlivosti(String nazov, int rok_poistenia, String IdPoskytovatela) {

        super(nazov, rok_poistenia);
        this.IdPoskytovatela = IdPoskytovatela;

    }

    public String getIdPoskytovatela() {

        return IdPoskytovatela;

    }

    @Override
    public boolean equals(Object obj) {

        if (this == obj) {

            return true;

        }

        if ( getClass() != obj.getClass() || obj == null ) {

            return false;
        }

        PoskytovatelZdravotnejStarostlivosti poskytovatel = (PoskytovatelZdravotnejStarostlivosti) obj;

        return IdPoskytovatela.equals(poskytovatel.IdPoskytovatela);

    }

    @Override
    public int hashCode() {

        return Objects.hash(IdPoskytovatela);

    }
}

