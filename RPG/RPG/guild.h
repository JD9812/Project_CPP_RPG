#ifndef JD_GUILD_H
#define JD_GUILD_H
#include <string>
#include "character.h"

namespace JD {

	class Guild
	{
		std::string m_teamName{};
		Character** m_members{};
		size_t m_size{};


	public:
		Guild() = default;
		Guild(const std::string name);

		Guild(const Guild& other);
		Guild& operator=(const Guild& other);
		Guild(Guild&& other) noexcept;
		Guild& operator=(Guild&& other) noexcept;
		~Guild();

		void addMember(const Character* c);

		void removeMember(const std::string& c);

		Character* operator[](size_t idx) const;

		void showMembers() const;

	};
}

#endif
