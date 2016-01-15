#pragma once
#include <string>
#include <Windows.h>
#include <direct.h>
namespace ProgramManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MainWindows
	/// </summary>
	public ref class MainWindows : public System::Windows::Forms::Form
	{
	public:
		MainWindows(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MainWindows()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Start;
	protected:

	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: String^ PATH_TO_ACQUIRE_DATA = "../";
	private: String^ PATH_TO_INTERPRETE_DATA = "../";
	private: String^ PATH_TO_OTHERS = "../";
	
	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void);
		System::Void Start_Click(System::Object^  sender, System::EventArgs^  e);
		#pragma endregion;

	};
}
