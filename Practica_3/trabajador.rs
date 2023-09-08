use std::{fs, io::Write, error::Error};

struct Trabajador{
    id: i32,
    nombre: String,
    sueldo: i64,
}

struct Nomina{
    trabajadores: Vec<Trabajador>,
}

impl Trabajador {
    fn new(id: i32, nombre:String, sueldo: i64) -> Trabajador {
        Trabajador {
            id,
            nombre,
            sueldo,
        }
    }
}

impl Nomina {
    fn new() -> Nomina {
        Nomina {
            trabajadores: Vec::new(),
        }
    }

    fn add_trabajador(&mut self, trabajador: Trabajador) {
        self.trabajadores.push(trabajador);
    }

    fn print(&self) {
        for trabajador in &self.trabajadores {
            println!("{:?},{:?},{:?}", trabajador.id, trabajador.nombre, trabajador.sueldo);
        }
    }

    fn save_to_file(&self) -> Result<(), std::io::Error> {
        let mut file = fs::File::open("nomina.csv")?;

        let mut line = String::new();
        line = format!("{:?},{:?},{:?}", self.trabajadores[0].id, self.trabajadores[0].nombre, self.trabajadores[0].sueldo );
        file.write_all(line.as_bytes());

        return Ok(());
    }
}

fn main() {
    let mut n_1 = Nomina::new();
    let t_1 = Trabajador::new(3241234, "Juan".to_string(), 999999900);

    n_1.add_trabajador(t_1);
    n_1.print();
    n_1.save_to_file();
}
