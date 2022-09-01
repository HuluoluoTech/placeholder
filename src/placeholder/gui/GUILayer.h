#pragma once

#include "../core/Layer.h"

#include "../events/EventApplication.h"
#include "../events/EventKey.h"
#include "../events/EventMouse.h"

namespace Placeholder {

	class GUILayer : public Layer
	{
	public:
		GUILayer();
		~GUILayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
		
		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
	};

}
