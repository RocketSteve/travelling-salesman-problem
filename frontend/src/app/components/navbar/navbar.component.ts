import {Component, ElementRef, ViewChild} from '@angular/core';
import {GetTspPathsService} from "../../services/get-tsp-paths.service";
import {TspInstanceService} from "../../services/tsp-instance.service";

@Component({
  selector: 'app-navbar',
  templateUrl: './navbar.component.html',
  styleUrls: ['./navbar.component.css']
})
export class NavbarComponent {

  @ViewChild('instance', {read: ElementRef}) instanceInput!: ElementRef<HTMLTextAreaElement>;

  constructor(private getTspPathsService: GetTspPathsService, private tspInstanceService: TspInstanceService) {
  }

  sendInstanceBtnHandler(): void {
    if (this.tspInstanceService.checkValidTspInstance(this.instanceInput.nativeElement.value)) {
      this.tspInstanceService.getTspInstance(this.instanceInput.nativeElement.value);
      this.getTspPathsService.sendInstance(this.instanceInput.nativeElement.value);
    } else alert("Invalid TSP instance");
  }

}
