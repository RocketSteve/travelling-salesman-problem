import {NgModule} from '@angular/core';
import {BrowserModule} from '@angular/platform-browser';
import { GraphComponent } from './graph/graph.component';

import {AppComponent} from './app.component';

@NgModule({
  declarations: [
    AppComponent,
      GraphComponent
  ],
  imports: [
    BrowserModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule {
}
