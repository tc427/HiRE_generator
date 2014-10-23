#include "molecule.hpp"
#include "chain.hpp"
#include "atom.hpp"
#include "residue.hpp"
#include "vector3d.hpp"
#include "param/fa2cgParam.hpp"

#include <map>
#include <vector>
#include <algorithm> // for find

class Fa2cg
{
	public:
		Fa2cg();
		static void fa2cg(Molecule &molecule);

	private:
		static void transformResidue(Residue &residue);
		static void normaliseResidue(Residue &residue);
		static Vector3d getCoordFromAtomVector(std::vector<Atom>);
		static int getMaxNAtom(Molecule &molecule);

};
