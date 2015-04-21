#include "options.hpp"

using namespace std;

extern istream *iss;
extern ostream *oss;
extern fstream ifs;
extern fstream ofs;
extern int factor;

void
opt_input(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la entrada
	// estándar. De lo contrario, abrimos un archivo en modo
	// de lectura.
	//
	if (arg == "-") {
		iss = &cin;
	} else {
		ifs.open(arg.c_str(), ios::in);
		iss = &ifs;
	}

	// Verificamos que el stream este OK.
	//
	if (!iss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

void
opt_output(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la salida
	// estándar. De lo contrario, abrimos un archivo en modo
	// de escritura.
	//
	if (arg == "-") {
		oss = &cout;
	} else {
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}

	// Verificamos que el stream este OK.
	//
	if (!oss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

void opt_help(string const &arg)
{
	cout << "cmdline [-i stream_in] [-o stram_out] [--topology file_topology] [--print-topology stream_out]"
	     << endl;
	exit(0);
}

void
opt_factor(string const &arg)
{
	istringstream iss(arg);
	
	// Intentamos extraer el factor de la línea de comandos.
	// Para detectar argumentos que únicamente consistan de 
	// números enteros, vamos a verificar que EOF llegue justo
	// después de la lectura exitosa del escalar.
	//
	if (!(iss >> factor)
	    || !iss.eof()) {
		cerr << "non-integer factor: "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}

	if (iss.bad()) {
		cerr << "cannot read integer factor."
		     << endl;
		exit(1);
	}
}

