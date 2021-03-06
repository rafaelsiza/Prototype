/********************************************************************
 *             a  A                                                        
 *            AM\/MA                                                         
 *           (MA:MMD                                                         
 *            :: VD
 *           ::  º                                                         
 *          ::                                                              
 *         ::   **      .A$MMMMND   AMMMD     AMMM6    MMMM  MMMM6             
 +       6::Z. TMMM    MMMMMMMMMDA   VMMMD   AMMM6     MMMMMMMMM6            
 *      6M:AMMJMMOD     V     MMMA    VMMMD AMMM6      MMMMMMM6              
 *      ::  TMMTMC         ___MMMM     VMMMMMMM6       MMMM                   
 *     MMM  TMMMTTM,     AMMMMMMMM      VMMMMM6        MMMM                  
 *    :: MM TMMTMMMD    MMMMMMMMMM       MMMMMM        MMMM                   
 *   ::   MMMTTMMM6    MMMMMMMMMMM      AMMMMMMD       MMMM                   
 *  :.     MMMMMM6    MMMM    MMMM     AMMMMMMMMD      MMMM                   
 *         TTMMT      MMMM    MMMM    AMMM6  MMMMD     MMMM                   
 *        TMMMM8       MMMMMMMMMMM   AMMM6    MMMMD    MMMM                   
 *       TMMMMMM$       MMMM6 MMMM  AMMM6      MMMMD   MMMM                   
 *      TMMM MMMM                                                           
 *     TMMM  .MMM                                         
 *     TMM   .MMD       ARBITRARY·······XML········RENDERING                           
 *     TMM    MMA       ====================================                              
 *     TMN    MM                               
 *      MN    ZM                       
 *            MM,
 *
 * 
 *      AUTHORS: Miro Keller
 *      
 *      COPYRIGHT: ©2011 - All Rights Reserved
 *
 *      LICENSE: see License.txt file
 *
 *      WEB: http://axr.vg
 *
 *      THIS CODE AND INFORMATION ARE PROVIDED "AS IS"
 *      WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED
 *      OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 *      IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 *      FITNESS FOR A PARTICULAR PURPOSE.
 *
 ********************************************************************
 *
 *      FILE INFORMATION:
 *      =================
 *      Last changed: 2011/06/11
 *      HSS version: 1.0
 *      Core version: 0.3
 *      Revision: 1
 *
 ********************************************************************/

#include "HSSRgba.h"
#include "../parsing/HSSExpression.h"
#include "../parsing/HSSConstants.h"

using namespace AXR;

HSSRgba::HSSRgba()
:HSSObject()
{
    this->type = HSSObjectTypeRgba;
    
    this->red = this->green = this->blue = 0.;
    this->alpha = 255.;
}

HSSRgba::~HSSRgba()
{
    
}

std::string HSSRgba::toString()
{
    if (this->isNamed()) {
        return std::string("HSSRgba: ").append(this->name);
    } else {
        return "Annonymous HSSRgba";
    }
}

std::string HSSRgba::defaultObjectType(std::string property)
{
    if (property == "red" || property == "green" || property == "blue" || property == "alpha" ){
        return "value";
    } else {
        return HSSObject::defaultObjectType(property);
    }
}

//bool HSSRgba::isKeyword(std::string value, std::string property)
//{
//    if (value == "transparent"){
//        return true;
//    }
//    
//    //if we reached this far, let the superclass handle it
//    return HSSObject::isKeyword(value, property);
//}


//FIXME: split into individual setters and call them from here
void HSSRgba::setProperty(std::string name, HSSParserNode::p value)
{
    if( name == "red" ){
        this->red = this->_setLDProperty(
                                        &HSSRgba::redChanged,
                                        value,
                                        255.,
                                        HSSObservablePropertyRed,
                                        this->observedRed,
                                        this->observedRedProperty
                                        );
        
    } else if( name == "green" ){
        this->green = this->_setLDProperty(
                                         &HSSRgba::greenChanged,
                                         value,
                                         255.,
                                         HSSObservablePropertyGreen,
                                         this->observedGreen,
                                         this->observedGreenProperty
                                         );
    } else if( name == "blue" ){
        this->blue = this->_setLDProperty(
                                         &HSSRgba::blueChanged,
                                         value,
                                         255.,
                                         HSSObservablePropertyBlue,
                                         this->observedBlue,
                                         this->observedBlueProperty
                                         );
    } else if( name == "alpha" ){
        this->alpha = this->_setLDProperty(
                                         &HSSRgba::alphaChanged,
                                         value,
                                         255.,
                                         HSSObservablePropertyAlpha,
                                         this->observedAlpha,
                                         this->observedAlphaProperty
                                         );
    } else {
        HSSObject::setProperty(name, value);
    }
}

long double HSSRgba::getRed() { return this->red; }
void HSSRgba::redChanged(AXR::HSSObservableProperty source, void *data)
{
    
}

long double HSSRgba::getGreen() { return this->green; }
void HSSRgba::greenChanged(AXR::HSSObservableProperty source, void *data)
{
    
}

long double HSSRgba::getBlue() { return this->blue; }
void HSSRgba::blueChanged(AXR::HSSObservableProperty source, void *data)
{
    
}

long double HSSRgba::getAlpha() { return this->alpha; }
void HSSRgba::alphaChanged(AXR::HSSObservableProperty source, void *data)
{
    
}

long double HSSRgba::_setLDProperty(
                                             void(HSSRgba::*callback)(HSSObservableProperty property, void* data),
                                             HSSParserNode::p         value,
                                             long double              percentageBase,
                                             HSSObservableProperty    observedSourceProperty,
                                             HSSObservable *          &observedStore,
                                             HSSObservableProperty    &observedStoreProperty
                                             )
{
    long double ret;
    
    HSSParserNodeType nodeType = value->getType();
    switch (nodeType) {
        case HSSParserNodeTypeNumberConstant:
        {
            HSSNumberConstant::p numberValue = boost::static_pointer_cast<HSSNumberConstant>(value);
            ret = numberValue->getValue();
            break;
        }
            
        case HSSParserNodeTypePercentageConstant:
        {
            HSSPercentageConstant::p percentageValue = boost::static_pointer_cast<HSSPercentageConstant>(value);
            ret = percentageValue->getValue(255.0);
            break;
        }
            
        case HSSParserNodeTypeExpression:
        {
            HSSExpression::p expressionValue = boost::static_pointer_cast<HSSExpression>(value);
            expressionValue->setPercentageBase(255.0);
            //expressionValue->setScope(scope);
            ret = expressionValue->evaluate();
            if(callback != NULL){
                expressionValue->observe(HSSObservablePropertyValue, observedSourceProperty, this, new HSSValueChangedCallback<HSSRgba>(this, callback));
                observedStore = expressionValue.get();
                observedStoreProperty = HSSObservablePropertyValue;
            }
            
            break;
        }
            
        case HSSParserNodeTypeKeywordConstant:
            
            break;
            
        default:
            throw "unknown parser node type while setting value for HSSRGBA property";
            break;
    }
    
    return ret;
}







