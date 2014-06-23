
#include "options.hpp"
using namespace std;
//HOLA
extern istream *iss_net, *iss_faults;
extern ostream *oss_net, *oss_faults;
extern fstream ifs_net, ifs_faults;
extern fstream ofs_net, ofs_faults;
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
void
opt_input(string const &arg)
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
void
opt_output(string const &arg)
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
	cout << "cmdline -f factor [-i file] [-o file]"
	     << endl;
	exit(0);
}
