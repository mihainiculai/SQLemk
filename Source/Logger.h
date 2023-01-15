#pragma once

void log(const string& mesaj) {
	if (!logger) return;
	
	ofstream log(loggerFolder, ios::app);
	time_t now = time(nullptr);
	string time = ctime(&now);
	log << "[" << time.substr(0, time.length() - 1) << "] " << mesaj << endl;
	log.close();
}
