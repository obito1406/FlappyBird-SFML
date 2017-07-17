#pragma once

namespace FlappyBird
{
	class State
	{
	public: 
		virtual void Init() = 0;

		virtual void HandleInput() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw( float dt) = 0; //dt = Time differences between frames. Allows to make game frame independant.

		virtual void Pause() {};
		virtual void Resume() {};

		/*NOTE: Only pure virtual methods MUST be implemented by the derived class, virtual non pure methods can or can not be implemented.**/
	};

}

