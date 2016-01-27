#ifndef _LOADER_H_

namespace MFT
{
	class Loader
	{
	public:
		Loader();
		~Loader();

	public:
		bool load(const std::string filename);
	};
}

#endif /* _LOADER_H_ */