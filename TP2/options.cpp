#include "options.hpp"

using namespace std;

extern istream *iss_net, *iss_faults;
extern ostream *oss_net, *oss_faults;
extern fstream ifs_net, ifs_faults;
extern fstream ofs_net, ofs_faults;
extern unsigned int configThreshold;
//extern option_t options[];

void opt_topology(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la entrada
	// estándar. De lo contrario, abrimos un archivo en modo
	// de lectura.
	//
	if (arg == "-") {
		iss_net = &cin;
	} else {
		ifs_net.open(arg.c_str(), ios::in);
		iss_net = &ifs_net;
	}

	// Verificamos que el stream este OK.
	//
	if (!iss_net->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}
void opt_print_topology(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la salida
	// estándar. De lo contrario, abrimos un archivo en modo
	// de escritura.
	//
	if (arg == "-") {
		oss_net = &cout;
	} else {
		ofs_net.open(arg.c_str(), ios::out);
		oss_net = &ofs_net;
	}

	// Verificamos que el stream este OK.
	//
	if (!oss_net->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

void opt_input(string const &arg)
{

	if (arg == "-") {
		iss_faults = &cin;
	} else {
		ifs_faults.open(arg.c_str(), ios::in);
		iss_faults = &ifs_faults;
	}

	// Verificamos que el stream este OK.
	//
	if (!iss_faults->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

void opt_output(string const &arg)
{
	if (arg == "-") {
		oss_faults = &cout;
	} else {
		ofs_faults.open(arg.c_str(), ios::out);
		oss_faults = &ofs_faults;
	}

	if (!oss_faults->good()) {
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

void opt_threshold(string const &arg)
{
	istringstream iss(arg);

	// Intentamos extraer el umbral desde la línea de comandos.
	// Para detectar argumentos que únicamente consistan de
	// números naturales, vamos a verificar que EOF llegue justo
	// después de la lectura exitosa del escalar.
	//
	if (!(iss >> configThreshold) || !iss.eof() || configThreshold<1)
    {
		cerr << "threshold must be positive: "
		     << arg
		     << endl;
		exit(1);
	}

	if (iss.bad()) {
		cerr << "cannot read threshold."
		     << endl;
		exit(1);
	}
}
