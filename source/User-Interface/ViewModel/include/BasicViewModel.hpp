#ifndef STAFFDEMO_REFACTOR_BASICVIEWMODEL_HPP
#define STAFFDEMO_REFACTOR_BASICVIEWMODEL_HPP
//#include "../../Core/include/AppSettings.hpp"
//#include "AppSettings.hpp"
#include <memory>
#include "../../../Business-logic/Core/include/AppSettings.hpp"
#include <boost/signals2.hpp>
#include "../../../Business-logic/Theme/include/Theme.hpp"

///@namespace viewModel
namespace viewModel {

    ///@class BasicViewModel
    ///@brief Базовая модель представления
    ///@details Базовая модель представления, лежащая в основе представлений
    ///@see AppSettings
    ///@see ThemeManager
    ///@addtogroup ViewModel
    class BasicViewModel {
    protected:
        std::weak_ptr<core::AppSettings> appSettings;

        explicit BasicViewModel(std::shared_ptr<core::AppSettings> sharedPtr);

    public:
        ~BasicViewModel();

        virtual theme::Theme& getTheme() const;

        virtual std::string getTranslate(const std::string& key, const std::unordered_map<std::string, std::string>& placeholder={}) const;
        boost::signals2::signal<void()> ViewUpdateRequest;

    };

} // viewModel

#endif //STAFFDEMO_REFACTOR_BASICVIEWMODEL_HPP
