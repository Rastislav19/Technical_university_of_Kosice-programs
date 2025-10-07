public class ZdravotnyZaznam {
        private String sluzba;
        private double cena;

        public ZdravotnyZaznam(String sluzba, double cena) {
            this.sluzba = sluzba;
            this.cena = cena;
        }

        public String getSluzba() {
            return sluzba;
        }

        public double getCena() {
            return cena;
        }
}

