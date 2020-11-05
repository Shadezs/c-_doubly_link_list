#include"memorymanager.h"

#include<iostream>

using std::cout;
using std::endl;
namespace arraybased {
	const int MAX_ALLOC_TRACK = 500;
	class AllocationList {
	public:
		AllocationList() : m_numEntries(0) { }

		void printItems() const {
			for (int i = 0; i < m_numEntries; i++) {
				const Entry &p = m_dispatched[i];
				cout << p.addr << " " << p.size << " " << p.func << " " << p.line << endl;
			}
		}
		void	add(void* item, char const* file, char const* func, int line, std::size_t sz, bool isArray) {
			if (m_numEntries < MAX_ALLOC_TRACK) {
				m_dispatched[m_numEntries].addr = item;
				m_dispatched[m_numEntries].file = file;
				m_dispatched[m_numEntries].func = func;
				m_dispatched[m_numEntries].line = line;
				m_dispatched[m_numEntries].size = sz;
				m_dispatched[m_numEntries].isArray = isArray;
				m_numEntries++;

			}
		}
		bool	deleteItem(void* item) {

			if (m_numEntries == 0) return false;

			int index = -1;
			for (int i = 0; i < m_numEntries; i++) {
				if (m_dispatched[i].addr == item) {
					index = i;
					break;
				}
			}
			if (index < 0 || index == m_numEntries) {
				return false;
			}
			if (index == m_numEntries - 1) {
				m_numEntries--;
				return true;
			}
			for (int i = index; i < m_numEntries - 1; i++) {
				m_dispatched[i] = m_dispatched[i + 1];
			}
			m_numEntries--;
			return true;
		}
		int size() {
			return m_numEntries;
		}
		void reset() { m_numEntries = 0; }
		
	private:
		struct Entry {
			void* addr;
			char const* file;
			char const* func;
			int line;
			std::size_t size;
			bool isArray;
		};

		Entry m_dispatched[MAX_ALLOC_TRACK];
		int m_numEntries;
	};
}

//Global :( debugging memory map 
arraybased::AllocationList g_allocList;
void reset() {
	g_allocList.reset();
}
void memoryReport() {
	g_allocList.printItems();
}
int getNumAlloc() {
	return g_allocList.size();
}
void* alloc(std::size_t sz, char const* file, char const*  func, int line, bool isArray = false) {
	void* ptr = std::malloc(sz);
	g_allocList.add(ptr, file, func, line, sz, isArray);
	return ptr;
}

void* operator new(std::size_t sz, char const* file, char const*  func, int line) noexcept {
	return alloc(sz, file, func, line, false);
}

void* operator new [](std::size_t sz, char const* file, char const*  func, int line) noexcept {
	return alloc(sz, file, func, line, true);
}

void operator delete(void* ptr) noexcept  {
	g_allocList.deleteItem(ptr);
	std::free(ptr);
}
void operator delete [](void* ptr) noexcept {
	g_allocList.deleteItem(ptr);
	std::free(ptr);
}