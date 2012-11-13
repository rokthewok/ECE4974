#ifndef TABLEGENERATOR_H
#define TABLEGENERATOR_H

class TableGenerator {
	public:
		~TableGenerator();
		TableGenerator * getTableGenerator();
		std::vector * generateSine( Oscillator & oscillator ) const;
		std::vector * generateSquare( Oscillator & oscillator ) const;
		std::vector * generateTriangle( Oscillator & oscillator ) const;
		std::vector * generateSawTooth( Oscillator & oscillator ) const;
	private:
		TableGenerator();
};

#endif // TABLEGENERATOR_H
