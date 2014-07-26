#pragma once

using namespace std;

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "libtorrent.hpp"
#include "Torrent.hpp"

namespace gt
{
	class Core
	{
	private:
		vector<shared_ptr<Torrent>> m_torrents;
		libtorrent::session m_session;
		bool m_running;
	public:
		Core();

		static bool isMagnetLink(string const& link);

		static string getDefaultSavePath();
		inline vector<shared_ptr<Torrent>> &getTorrents()
		{
			return m_torrents;
		};

		void loadSession(string path);
		void saveSession(string path);
		shared_ptr<Torrent> addTorrent(string path, vector<char> *resumedata = nullptr);

		void removeTorrent(shared_ptr<Torrent>);

		inline bool isRunning() const
		{
			return m_running;
		};
		void shutdown();
		void update();
	};
}
