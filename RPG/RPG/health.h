#ifndef JD_HEALTH_H
#define JD_HEALTH_H

namespace JD
{
	// Damaged received is reduced by half.
	class SuperHealth
	{
		double m_value = 1000.0;

	public:

		//Reduced damaged received by half.
		SuperHealth& operator-=(int dmg)
		{
			m_value -= dmg / 2.0;
			return *this;
		}

		// Sets health to new value.
		SuperHealth& operator=(int newVal)
		{
			m_value = newVal;
			return *this;
		}

		// Gets int health value.
		operator int() const
		{
			return static_cast<int>(m_value);
		}
	};

	// Health cant be reduced.
	struct InfiniteHealth
	{ 
		// Health cant modified
		InfiniteHealth& operator-=(int) { return *this; }

		// Health cant modified
		InfiniteHealth& operator=(int) { return *this; }

		// Gets int health value.
		operator int() const { return 1; }
	};
}
#endif