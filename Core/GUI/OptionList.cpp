#include "OptionList.hpp"

namespace gui
{

OptionList::OptionList()
    : mSelectedOption(0ULL),
    mHighlight(0, 0, {0, 0, 0, 0})
{}

void OptionList::addOption(const Option& option)
{
    mOptions.push_back(option);
}

void OptionList::selectNext()
{
    const size_t n = mOptions.size();

    if(n <= 0ULL){ return; }

    mSelectedOption = (n + mSelectedOption + 1) % n;
}

void OptionList::selectPrev()
{
    const size_t n = mOptions.size();

    if(n <= 0ULL){ return; }
    
    mSelectedOption = (n + mSelectedOption - 1) % n;
}

void OptionList::executeSelectedOption()
{
    mOptions[mSelectedOption].onAction();
}

void OptionList::draw(Window& renderTarget, 
    const Vec2i& position)
{
    const size_t n = mOptions.size();
    Vec2i currentPosition = getPosition();
    
    for(size_t i = 0ULL; i < n; i++)
    {
        if(i == mSelectedOption)
        {
            mHighlight.setSize({mOptions[i].image.width, mOptions[i].image.height});
            mHighlight.setColor(mOptions[i].color);

            renderTarget.draw(mHighlight, currentPosition);
        }

        renderTarget.draw(mOptions[i].image, currentPosition);

        currentPosition.y += mOptions[i].image.height + 2;
    }
}

}