#ifndef GUIGTK_HPP
#define GUIGTK_HPP

#include <gui/core/Base.hpp>
#include <gtkmm/settings.h>
#include <gtkmm/main.h>

class GuiGtk : public GuiBase
{
public:
	GuiGtk(int argc, char **argv);
	std::string getOpenFileDialog(){return"";}
	std::string getSaveFileDialog(){return"";}

	void update();
};

#endif